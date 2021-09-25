from bs4 import BeautifulSoup
import requests
r = requests.get('http://web.archive.org/web/20140301191716/http://pokemondb.net/pokedex/national')
soup = BeautifulSoup(r.text, 'html.parser')
for card in soup.select('.infocard-tall'):
    name = card.select_one('.ent-name').text
    types = []
    for type in card.select('a.itype'):
        types.append(type.text)
    print(f'"{name}\\n{" ".join(types)}",')
