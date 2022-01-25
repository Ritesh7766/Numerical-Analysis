```python
import pandas as pd
import matplotlib.pyplot as plt
from utils.CSVGenerator import write_csv
from utils.config import MY_CONFIG
from utils.Interpolate import newton_forward, get_forward_table
from utils.Roots import bisection, newton_rhapson, regula_falsi, secant, csv_bisection, csv_newton_rhapson, csv_regula_falsi, csv_secant
import numpy as np
import mpld3
from ctypes import *
mpld3.enable_notebook()
```


```python
def f(x):
    return (x * x - 2929292929292929.495249572957289)

def df(x):
    return 2 * x
```


```python
def func(x):
    return x * x - 3.0
```


```python
regula_falsi(0.0, 9999.0, func, 0.00000000000001)
```




    1.7320508075392307




```python
regula_falsi(0.0, 99999999999999.0, f, 0.00000000000001)
```




    54122942.71550889




```python
newton_rhapson(1.0, func, df, 0.0000000001)
```




    1.7320508075688774




```python
newton_rhapson(1.0, f, df, 0.0000001)
```




    54122942.72573259




```python
bisection(0.0, 99999999.0, func, 0.00000000001)
```




    1.7320508075638892




```python
bisection(0.0, 9999999999999.0, f, 0.00000000001)
```




    54122942.72573258




```python
secant(0.0, 99999999.0, func, 0.00000001)
```




    1.7320508075688774




```python
secant(0.0, 999999999999.0, f, 0.0000000001)
```




    54122942.72573259




```python
csv_bisection(0.0, 999999999999999.0, func, 0.000000001, 'bisect.csv')
```


```python
bisect = pd.read_csv('./test_cases/bisect.csv')
```


```python
bisect
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>start_interval</th>
      <th>end_interval</th>
      <th>new_approximation</th>
      <th>prev_approximation</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0.000000</td>
      <td>5.000000e+14</td>
      <td>5.000000e+14</td>
      <td>0.000000e+00</td>
    </tr>
    <tr>
      <th>1</th>
      <td>0.000000</td>
      <td>2.500000e+14</td>
      <td>2.500000e+14</td>
      <td>5.000000e+14</td>
    </tr>
    <tr>
      <th>2</th>
      <td>0.000000</td>
      <td>1.250000e+14</td>
      <td>1.250000e+14</td>
      <td>2.500000e+14</td>
    </tr>
    <tr>
      <th>3</th>
      <td>0.000000</td>
      <td>6.250000e+13</td>
      <td>6.250000e+13</td>
      <td>1.250000e+14</td>
    </tr>
    <tr>
      <th>4</th>
      <td>0.000000</td>
      <td>3.125000e+13</td>
      <td>3.125000e+13</td>
      <td>6.250000e+13</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>75</th>
      <td>1.732051</td>
      <td>1.732051e+00</td>
      <td>1.732051e+00</td>
      <td>1.732051e+00</td>
    </tr>
    <tr>
      <th>76</th>
      <td>1.732051</td>
      <td>1.732051e+00</td>
      <td>1.732051e+00</td>
      <td>1.732051e+00</td>
    </tr>
    <tr>
      <th>77</th>
      <td>1.732051</td>
      <td>1.732051e+00</td>
      <td>1.732051e+00</td>
      <td>1.732051e+00</td>
    </tr>
    <tr>
      <th>78</th>
      <td>1.732051</td>
      <td>1.732051e+00</td>
      <td>1.732051e+00</td>
      <td>1.732051e+00</td>
    </tr>
    <tr>
      <th>79</th>
      <td>1.732051</td>
      <td>1.732051e+00</td>
      <td>1.732051e+00</td>
      <td>1.732051e+00</td>
    </tr>
  </tbody>
</table>
<p>80 rows × 4 columns</p>
</div>




```python
csv_regula_falsi(0.0, 9999.0, func, 0.00000000001, 'regula.csv')
```


```python
regula = pd.read_csv('./test_cases/regula.csv')
```


```python
regula
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>start_interval</th>
      <th>end_interval</th>
      <th>new_approximation</th>
      <th>prev_approximation</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0.000300</td>
      <td>9999.0</td>
      <td>0.000300</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th>1</th>
      <td>0.000600</td>
      <td>9999.0</td>
      <td>0.000600</td>
      <td>0.000300</td>
    </tr>
    <tr>
      <th>2</th>
      <td>0.000900</td>
      <td>9999.0</td>
      <td>0.000900</td>
      <td>0.000600</td>
    </tr>
    <tr>
      <th>3</th>
      <td>0.001200</td>
      <td>9999.0</td>
      <td>0.001200</td>
      <td>0.000900</td>
    </tr>
    <tr>
      <th>4</th>
      <td>0.001500</td>
      <td>9999.0</td>
      <td>0.001500</td>
      <td>0.001200</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>53693</th>
      <td>1.732051</td>
      <td>9999.0</td>
      <td>1.732051</td>
      <td>1.732051</td>
    </tr>
    <tr>
      <th>53694</th>
      <td>1.732051</td>
      <td>9999.0</td>
      <td>1.732051</td>
      <td>1.732051</td>
    </tr>
    <tr>
      <th>53695</th>
      <td>1.732051</td>
      <td>9999.0</td>
      <td>1.732051</td>
      <td>1.732051</td>
    </tr>
    <tr>
      <th>53696</th>
      <td>1.732051</td>
      <td>9999.0</td>
      <td>1.732051</td>
      <td>1.732051</td>
    </tr>
    <tr>
      <th>53697</th>
      <td>1.732051</td>
      <td>9999.0</td>
      <td>1.732051</td>
      <td>1.732051</td>
    </tr>
  </tbody>
</table>
<p>53698 rows × 4 columns</p>
</div>




```python
csv_newton_rhapson(1.0, f, df, 0.000001, 'newton.csv')
```


```python
newton = pd.read_csv('./test_cases/newton.csv')
```


```python
newton
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>new_approximation</th>
      <th>prev_approximation</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1.464646e+15</td>
      <td>1.000000e+00</td>
    </tr>
    <tr>
      <th>1</th>
      <td>7.323232e+14</td>
      <td>1.464646e+15</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3.661616e+14</td>
      <td>7.323232e+14</td>
    </tr>
    <tr>
      <th>3</th>
      <td>1.830808e+14</td>
      <td>3.661616e+14</td>
    </tr>
    <tr>
      <th>4</th>
      <td>9.154040e+13</td>
      <td>1.830808e+14</td>
    </tr>
    <tr>
      <th>5</th>
      <td>4.577020e+13</td>
      <td>9.154040e+13</td>
    </tr>
    <tr>
      <th>6</th>
      <td>2.288510e+13</td>
      <td>4.577020e+13</td>
    </tr>
    <tr>
      <th>7</th>
      <td>1.144255e+13</td>
      <td>2.288510e+13</td>
    </tr>
    <tr>
      <th>8</th>
      <td>5.721275e+12</td>
      <td>1.144255e+13</td>
    </tr>
    <tr>
      <th>9</th>
      <td>2.860638e+12</td>
      <td>5.721275e+12</td>
    </tr>
    <tr>
      <th>10</th>
      <td>1.430319e+12</td>
      <td>2.860638e+12</td>
    </tr>
    <tr>
      <th>11</th>
      <td>7.151594e+11</td>
      <td>1.430319e+12</td>
    </tr>
    <tr>
      <th>12</th>
      <td>3.575797e+11</td>
      <td>7.151594e+11</td>
    </tr>
    <tr>
      <th>13</th>
      <td>1.787899e+11</td>
      <td>3.575797e+11</td>
    </tr>
    <tr>
      <th>14</th>
      <td>8.939494e+10</td>
      <td>1.787899e+11</td>
    </tr>
    <tr>
      <th>15</th>
      <td>4.469748e+10</td>
      <td>8.939494e+10</td>
    </tr>
    <tr>
      <th>16</th>
      <td>2.234878e+10</td>
      <td>4.469748e+10</td>
    </tr>
    <tr>
      <th>17</th>
      <td>1.117445e+10</td>
      <td>2.234878e+10</td>
    </tr>
    <tr>
      <th>18</th>
      <td>5.587358e+09</td>
      <td>1.117445e+10</td>
    </tr>
    <tr>
      <th>19</th>
      <td>2.793941e+09</td>
      <td>5.587358e+09</td>
    </tr>
    <tr>
      <th>20</th>
      <td>1.397495e+09</td>
      <td>2.793941e+09</td>
    </tr>
    <tr>
      <th>21</th>
      <td>6.997954e+08</td>
      <td>1.397495e+09</td>
    </tr>
    <tr>
      <th>22</th>
      <td>3.519907e+08</td>
      <td>6.997954e+08</td>
    </tr>
    <tr>
      <th>23</th>
      <td>1.801564e+08</td>
      <td>3.519907e+08</td>
    </tr>
    <tr>
      <th>24</th>
      <td>9.820805e+07</td>
      <td>1.801564e+08</td>
    </tr>
    <tr>
      <th>25</th>
      <td>6.401773e+07</td>
      <td>9.820805e+07</td>
    </tr>
    <tr>
      <th>26</th>
      <td>5.488763e+07</td>
      <td>6.401773e+07</td>
    </tr>
    <tr>
      <th>27</th>
      <td>5.412827e+07</td>
      <td>5.488763e+07</td>
    </tr>
    <tr>
      <th>28</th>
      <td>5.412294e+07</td>
      <td>5.412827e+07</td>
    </tr>
    <tr>
      <th>29</th>
      <td>5.412294e+07</td>
      <td>5.412294e+07</td>
    </tr>
    <tr>
      <th>30</th>
      <td>5.412294e+07</td>
      <td>5.412294e+07</td>
    </tr>
  </tbody>
</table>
</div>




```python
csv_secant(0.0, 99999999999.0, f, 0.00000001, 'secant.csv')
```


```python
secant = pd.read_csv('./test_cases/secant.csv')
```


```python
secant
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>start_interval</th>
      <th>end_interval</th>
      <th>new_approximation</th>
      <th>prev_approximation</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>2.929293e+04</td>
      <td>1.000000e+11</td>
      <td>2.929293e+04</td>
      <td>0.000000e+00</td>
    </tr>
    <tr>
      <th>1</th>
      <td>5.858584e+04</td>
      <td>1.000000e+11</td>
      <td>5.858584e+04</td>
      <td>2.929293e+04</td>
    </tr>
    <tr>
      <th>2</th>
      <td>8.787872e+04</td>
      <td>1.000000e+11</td>
      <td>8.787872e+04</td>
      <td>5.858584e+04</td>
    </tr>
    <tr>
      <th>3</th>
      <td>1.171715e+05</td>
      <td>1.000000e+11</td>
      <td>1.171715e+05</td>
      <td>8.787872e+04</td>
    </tr>
    <tr>
      <th>4</th>
      <td>1.464643e+05</td>
      <td>1.000000e+11</td>
      <td>1.464643e+05</td>
      <td>1.171715e+05</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>27272</th>
      <td>5.412294e+07</td>
      <td>1.000000e+11</td>
      <td>5.412294e+07</td>
      <td>5.412294e+07</td>
    </tr>
    <tr>
      <th>27273</th>
      <td>5.412294e+07</td>
      <td>1.000000e+11</td>
      <td>5.412294e+07</td>
      <td>5.412294e+07</td>
    </tr>
    <tr>
      <th>27274</th>
      <td>5.412294e+07</td>
      <td>1.000000e+11</td>
      <td>5.412294e+07</td>
      <td>5.412294e+07</td>
    </tr>
    <tr>
      <th>27275</th>
      <td>5.412294e+07</td>
      <td>1.000000e+11</td>
      <td>5.412294e+07</td>
      <td>5.412294e+07</td>
    </tr>
    <tr>
      <th>27276</th>
      <td>5.412294e+07</td>
      <td>1.000000e+11</td>
      <td>5.412294e+07</td>
      <td>5.412294e+07</td>
    </tr>
  </tbody>
</table>
<p>27277 rows × 4 columns</p>
</div>




```python

```
