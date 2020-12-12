import pandas as pd
import networkx as nx

elements = pd.read_csv("./elements.csv", sep=",", header=0, index_col=0)
print(elements)
print("number of elements is %d" % len(elements))