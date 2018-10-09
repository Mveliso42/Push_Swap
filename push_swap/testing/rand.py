# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    rand.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmtana <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 18:56:33 by mmtana            #+#    #+#              #
#    Updated: 2018/09/20 22:19:29 by mmtana           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random
# Change nums to run tests of "nums" length
nums = 500 
a = range(1,700)
for i in xrange(nums):
	b = a[random.randint(0, len(a)-i)]
	a.remove(b)
	print b
