#!/usr/bin/python3

import requests

def count_words(subreddit, word_list, after=None, counts=None):
    # Si counts est None, initialisez-le comme un dictionnaire vide
    if counts is None:
        counts = {}

    # Definir les en tetes pour la request HTTP
    headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) Chrome/85.0.4183.102 Safari/537.36'}

    # Construire L'URL de la request HTTP
    if after:
        url = f'https://www.reddit.com/r/{subreddit}/hot.json?after={after}'
    else:
        url = f'https://www.reddit.com/r/{subreddit}/hot.json'

    # Faire la request HTTP
    response = requests.get(url, headers=headers)

    # Vérifier si la requete a reussi (code 200)
    if response.status_code != 200:
        return None

    # Analyser la réponse JSON
    data = response.json()

    # Extraire les titres des articles
    posts = data['data']['children']
    for post in posts:
        title = post['data']['title'].lower()

    # Vérifier la présence des mots dans les titres
    for word in word_list:
        if word.lower() in title:
            counts[word] = counts.get(word, 0) + 1

    # Verifer s'il une page suivante (pagination)
    after = data['data']['after']

    # Si une page suivante existe, appeler la fonction count_words
    if after:
        count_words(subreddit, word_list, after, counts)
    else:
        # Si une page suivante n'existe pas, imprimer les résultats
        print_results(counts)
    


def print_results(counts):
    sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
    for word, count in sorted_counts:
        print(f'{word}: {count}')
