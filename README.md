# <samp>Learning polymorphism in C++</samp>

## <samp>Creanting a Calculator with multiple parameters</samp>

## <samp>Abstracting the flat geometric figure: Polygon</samp>

Podemos crear una abstracción general que contenga a Poligono como una especialización 
La estructura general será escalable y no nos limita solo a Poligonos. Sin embargo, en 
esta ocasión solo implementamos la abstracción de Poligonos, quedando los otros tipos 
para futuras implementaciones.

### <samp>Polygon class</samp>

Un poligono se define como una figura cerrada donde cada arista es un segmento de 
recta. Podemos clasificarla por la cantidad de aristas pero eso no ubica a la 
figura en un espacio.

Nosotros hacemos uso de puntos en el espacio bidimensional para describir a un 
poligono. El poligono se define como una cantidad finita de vértices (puntos) en 
el espacio bidimensional.

### <samp>Point class</samp>

Abstrae las coordenadas cartesianas de un vértice que pertenece a un Poligono. La 
función obligatoria que debe contener dicha clase es poder hallar la distancia 
entre dos puntos.

### <samp>Regular Polygon class</samp>

### <samp>Irregular Polygon class</samp>
