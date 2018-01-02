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

#include <stdio.h>

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
	*(hashmap->keychain) = NULL;
	return (hashmap);
}

/* Hash a string for a particular hash table */
int			hm_hash(t_hashmap *hashmap, const char *key)
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

/* Insert a key-value pair into a hash table. */
void		hm_insert(t_hashmap *hashmap, const char *key, const char *value)
{
	int				bin;
	t_hm_entry		*new;
	t_hm_entry		*next;
	t_hm_entry		*last;

	bin = hm_hash(hashmap, key);
	next = hashmap->table[bin];
	last = NULL;
	new = NULL;
	while (next != NULL && next->key != NULL && ft_strcmp(key, next->key->data) > 0)
	{
		last = next;
		next = next->next;
	}
	/* Update existing key. */
	if (next != NULL && next->key != NULL && ft_strcmp(key, next->key->data) == 0)
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
		/* thread key into keychain, push to front of keychain list*/
		new->key->next = *(hashmap->keychain);
		if ((*(hashmap->keychain)))
			(*(hashmap->keychain))->prev = new->key;
		(*(hashmap->keychain)) = new->key;
	}
}

/* Retrieve a key-value pair from hashmap. */
char	*hm_lookup(t_hashmap *hashmap, const char *key)
{
	int			bin;
	t_hm_entry	*pair;

	bin = hm_hash(hashmap, key);

	/* Step through bin looking for value */
	pair = hashmap->table[bin];
	while (pair != NULL && pair->key != NULL && ft_strncmp(key, (char*)(pair->key->data), ft_strlen(key)) > 0)
		pair = pair->next;
	/* Key doesn't exist. */
	if (pair == NULL || pair->key == NULL || ft_strncmp(key, (char*)(pair->key->data), ft_strlen(key)) != 0)
		return (NULL);
	return (pair->value);
}


void	hm_delete(t_hashmap *hashmap, const char *key)
{
	int			bin;
	t_hm_entry	*prev;
	t_hm_entry	*pair;

	bin = hm_hash(hashmap, key);
	prev = NULL;
	pair = hashmap->table[bin];
	/* entry is first element in bucket -> reset bucket header */
	if (pair != NULL && pair->key != NULL && ft_strncmp(key, (char*)(pair->key->data), ft_strlen(key)) == 0)
	{
		/* update keychain */
		if (ft_strncmp(key, (*(hashmap->keychain))->data, ft_strlen(key)) == 0)
			*(hashmap->keychain) = (*(hashmap->keychain))->next;	
		if (pair->key->prev) 
			pair->key->prev->next = pair->key->next;
		if (pair->key->next)
			pair->key->next->prev = pair->key->prev;
		/* reset bucket header */
		hashmap->table[bin] = pair->next;
		/* free memory */
		free(pair->key->data);
		free(pair->key);
		free(pair);
		return ;
	}
	/* find entry in bucket */
	while (pair != NULL && pair->key != NULL && ft_strncmp(key, (char*)(pair->key->data), ft_strlen(key)) > 0)
	{
		prev = pair;
		pair = pair->next;	
	}
	/* entry doesnt exist */
	if (pair == NULL || pair->key == NULL || ft_strncmp(key, (char*)(pair->key->data), ft_strlen(key)) != 0)
		return ;
	/* skip entry in bucket list */
	prev->next = pair->next;
	/* update keychain */
	if (ft_strncmp(key, (*(hashmap->keychain))->data, ft_strlen(key)) == 0)
		*(hashmap->keychain) = (*(hashmap->keychain))->next;
	if (pair->key->prev)
		pair->key->prev->next = pair->key->next;
	if (pair->key->next)
		pair->key->next->prev = pair->key->prev;
	free(pair->key->data);
	free(pair->key);
	free(pair);
	}