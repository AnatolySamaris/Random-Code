import requests
from bs4 import BeautifulSoup

url = 'https://parsinger.ru/html/index3_page_1.html'

'''
Задание - найти сумму артикулов в карточках товаров категории компьютерная мышь
Зачем? Да без понятия.
'''

response = requests.get(url)
response.encoding = 'utf-8' # Чтобы не было "краказябр"

bs = BeautifulSoup(response.text, 'lxml')

# Добываем ссылки на все страницы категории
pages_links = map(lambda x: x['href'], bs.find('div', 'pagen').find_all('a'))
pages = map(lambda x: 'https://parsinger.ru/html/' + x, pages_links)

article_counter = 0
for link in pages:
    try:
        page = requests.get(link)
        page.encoding = 'utf-8'
        soup = BeautifulSoup(page.text, 'lxml')
        
        # Достаем ссылки на карточки товаров на данной странице page
        items = map(lambda x: x['href'], soup.find('div', 'item_card').find_all('a', class_='name_item'))

        # Ходим по карточкам товаров и достаём артикулы
        for item_link in map(lambda x: 'https://parsinger.ru/html/' + x, items):
            try:
                item = requests.get(item_link)
                item.encoding = 'utf-8'
                item_bs = BeautifulSoup(item.text, 'lxml')
                article = item_bs.find('p', class_='article').text.split()[1]
                article_counter += int(article)
                
            except Exception as inside_error:
                print('Inside: ', inside_error)
                break
                
    except Exception as outside_error:
        print('Outside: ', outside_error)

print(article_counter)
