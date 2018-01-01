/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 11:15:06 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/31 11:36:55 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

/* Create a new hashtable. */
t_hashmap	*hm_new_map(int size_table)
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
	return (hashmap);
}

/* Hash a string for a particular hash table */
int			hm_hash(t_hashmap *hashmap, char *key)
{
	unsigned long int	hashval;
	size_t				i;

	/* Convert string to integer */
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

/* Create a key - value pair */
t_hm_entry		*hm_new_entry(char *key, char *value)
{
	t_hm_entry		*new;

	if (!(new = malloc(sizeof(t_hm_entry))))
		return (NULL);
	if (!(new->key = ft_strdup(key)))
		return (NULL);
	if (!(new->value = ft_strdup(value)))
		return (NULL);
	new->next = NULL;
	return (new);
}

/* Insert a key-value pair into a hash table. */
void		hm_insert(t_hashmap *hashmap, char *key, char *value)
{
	int			bin;
	t_hm_entry		*new;
	t_hm_entry		*next;
	t_hm_entry		*last;

	bin = hm_hash(hashmap, key);
	next = hashmap->table[bin];
	last = NULL;
	new = NULL;
	while (next != NULL && next->key != NULL && ft_strcmp(key, next->key) > 0)
	{
		last = next;
		next = next->next;
	}
	/* Update existing key. */
	if (next != NULL && next->key != NULL && ft_strcmp(key, next->key) == 0)
	{
		free(next->value);
		next->value = ft_strdup(value);
	}
	else
	{
		new = hm_new_entry(key, value);
		/* Insert at start of linked list in current bin. */
		if (next == hashmap->table[bin])
		{
			new->next = next;
			hashmap->table[bin] = new;
		}
		/* Insert at end of linked list in current bin. */
		else if (!next)
		{
			last->next = new;
		}
		/* Insert in the middle of linked list in current bin. */
		else
		{
			new->next = next;
			last->next = new;
		}
	}
}

/* Retrieve a key-value pair from hashmap. */
char	*hm_lookup(t_hashmap *hashmap, char *key)
{
	int		bin;
	t_hm_entry	*pair;

	bin = hm_hash(hashmap, key);

	/* Step through bin looking for value */
	pair = hashmap->table[bin];
	while (pair != NULL && pair->key != NULL && ft_strcmp(key, pair->key) > 0)
		pair = pair->next;
	/* Key doesn't exist. */
	if (pair == NULL || pair->key == NULL || ft_strcmp(key, pair->key) != 0)
		return (NULL);
	return (pair->value);
}