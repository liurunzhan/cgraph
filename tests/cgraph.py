#!/usr/bin/python3

import pandas as pd
import networkx as nx
import os

file = "elements.csv"
if os.path.exists(file):
	elements = pd.read_csv(file, sep=",", header=0, index_col=0)
	print(elements)
	print("number of elements is %d" % len(elements))

file = "rand_seed.csv"
if os.path.exists(file):
	rands = pd.read_csv(file, sep=",", header=None)
	print(rands.iloc[:,0].value_counts())
