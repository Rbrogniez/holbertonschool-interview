#!/usr/bin/python3
"""Module to count the occurrences of words in the titles of hot posts"""
import requests


def count_words(subreddit, word_list, after='', count={}):
    """
    Recursively counts the occurrences of a list of words in the titles of
    the hot posts of a subreddit.

    Args:
    - subreddit (str): the name of the subreddit to search in
    - word_list (list): words to search for in the titles
    - after (str): token to paginate through the subreddit's posts
    - count (dict): store the count of each word in the titles
    """
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    if after != '':
        url += '?after={}'.format(after)
    user = {'User-Agent': 'CountIt'}
    response = requests.get(url, headers=user, allow_redirects=False)
    if response.status_code > 300:
        return
    data = response.json().get('data')
    after = data.get('after')
    check_titles(count, word_list, data.get('children'))
    if after is None:
        print_result(count)
        return
    count_words(subreddit, word_list, after, count)


def print_result(count):
    """
    Prints the count of each key in the given dictionary in descending
    order of count.

    Args:
    - count (dict): words searched for and their respective counts
    """
    sorted_dict = dict(sorted(count.items(), key=lambda x: x[1], reverse=True))
    for key, value in sorted_dict.items():
        if value > 0:
            print('{}: {}'.format(key, value))


def check_titles(count, word_list, posts):
    """
    Count the occurrences of words from a given list in the titles of a list
    of Reddit posts.

    Args:
    - count (dict): store the word counts
    - word_list (list): words to search for
    - posts (list): Reddit posts
    """
    for post in posts:
        for word in post.get('data').get('title').lower().split():
            if word in [keyword.lower() for keyword in word_list]:
                if word not in count.keys():
                    count[word] = 1
                else:
                    count[word] += 1
