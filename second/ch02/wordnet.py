import nltk
from nltk.corpus import wordnet
print(wordnet.synsets('car'))
car = wordnet.synset('car.n.01')
print(car.definition())
print(car.lemma_names())
print(car.hypernym_paths()[0])

novel = wordnet.synset('novel.n.01')
car = wordnet.synset('car.n.01')
dog = wordnet.synset('dog.n.01')
motorcycle = wordnet.synset('motorcycle.n.01')
print(car.path_similarity(novel))
print(car.path_similarity(dog))
print(car.path_similarity(motorcycle))
