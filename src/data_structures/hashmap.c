/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 11:15:06 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/04 20:37:45 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

t_hashmap		*hm_new_map(int size_table)
{
	t_hashmap	*hashmap;
	int			i;

	if (size_table < 1 || !(hashmap = malloc(sizeof(t_hashmap))))
		return (NULL);
	if (!(hashmap->table = malloc(sizeof(t_hm_entry*) * size_table)))
		return (NULL);
	i = 0;
	while (i < size_table)
	{
		hashmap->table[i] = NULL;
		i++;
	}
	hashmap->size_table = size_table;
	*(hashmap->keychain) = NULL;
	return (hashmap);
}

int				hm_hash(t_hashmap *hashmap, const char *key)
{
	unsigned long int	hashval;
	size_t				i;

	i = 0;
	hashval = 0;
	while (hashval < ULONG_MAX && i < ft_strlen(key))
	{
		hashval = hashval << 8;
		hashval += key[i];
		i++;
	}
	return (hashval % hashmap->size_table);
}

t_hm_entry		*hm_new_entry(const char *key, const char *value)
{
	t_hm_entry		*new;

	if (!(new = malloc(sizeof(t_hm_entry))))
		return (NULL);
	new->key = dll_new_node((void*)key, ft_strlen(key));
	if (!(new->value = ft_strdup(value)))
		return (NULL);
	new->next = NULL;
	return (new);
}

void			hm_insert(t_hashmap *hashmap, const char *key,
					const char *value)
{
	int				bin;
	t_hm_entry		*new;
	t_hm_entry		*next;
	t_hm_entry		*last;

	bin = hm_hash(hashmap, key);
	next = hashmap->table[bin];
	last = NULL;
	new = NULL;
	while (next != NULL && next->key != NULL &&
			ft_strcmp(key, next->key->data) > 0)
	{
		last = next;
		next = next->next;
	}
	if (next != NULL && next->key != NULL &&
			ft_strcmp(key, next->key->data) == 0)
	{
		free(next->value);
		next->value = ft_strdup(value);
	}
	else
	{
		new = hm_new_entry(key, value);
		if (next == hashmap->table[bin])
		{
			new->next = next;
			hashmap->table[bin] = new;
		}
		else if (!next)
		{
			last->next = new;
		}
		else
		{
			new->next = next;
			last->next = new;
		}
		new->key->next = *(hashmap->keychain);
		if ((*(hashmap->keychain)))
			(*(hashmap->keychain))->prev = new->key;
		(*(hashmap->keychain)) = new->key;
	}
}
