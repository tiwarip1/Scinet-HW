import matplotlib.pyplot as plt
import numpy as np

l = [1.8,1.766,1.716,1.75,1.75,1.7,1.7,1.7,1.7,1.66,1.66,1.7,1.71,1.7,1.7,1.7]
plt.plot(np.arange(1,17),l)
plt.ylabel('Number of Cores')
plt.xlabel('Time taken (hours)')
plt.savefig('time_taken,png')