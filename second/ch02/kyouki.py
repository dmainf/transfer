import sys
sys.path.append('..')
import numpy as np
from common.util import preprocess

text = 'You say goodbye and I say hello.'
corpus, word_toid, id_to_word = preprocess(text)
print(corpus)
print(id_to_word)