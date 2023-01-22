#!/usr/bin/python3
""" Module that queries the Reddit API """


import requests


def count_words(subreddit, word_list, after='', word_count={}):
    """
    Method that parses the title of all hot articles,
    and prints a sorted count of given keywords.
    """
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    h = {'User-Agent': 'holberton_school'}
    payload = {'limit': '100', 'after': after}
    r = requests.get(url, headers=h, params=payload, allow_redirects=False)
    if r.status_code == 200:
        data = r.json().get('data')
        after = data.get('after')
        children = data.get('children')
        for child in children:
            title = child.get('data').get('title')
            for word in word_list:
                ocurrences = title.lower().split().count(word.lower())
                if ocurrences > 0:
                    if word in word_count:
                        word_count[word] += ocurrences
                    else:
                        word_count[word] = ocurrences

        if after is not None:
            return count_words(subreddit, word_list, after, word_count)
        else:
            if not len(word_count) > 0:
                return
            datas = sorted(word_count.items(),
                           key=lambda key_value: (-key_value[1], key_value[0]))
            for key, value in datas:
                print('{}: {}'.format(key.lower(), value))
    else:
        return
