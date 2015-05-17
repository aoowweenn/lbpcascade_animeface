# lbpcascade_animeface

The face detector for anime/manga using OpenCV.

Original release since 2011 at [OpenCVによるアニメ顔検出ならlbpcascade_animeface.xml](http://ultraist.hatenablog.com/entry/20110718/1310965532) (in Japanese)

## Usage

### C++ Example

```{r, engine='bash', count_lines}
cmake .
make
ln -s ../lbpcascade_animeface.xml
./AnifaceDetect ../figure/header_idolmaster_pre.png
```

### Python Example

```{r, engine='bash', count_lines}
cd examples
python detect.py ../figure/header_idolmaster_pre.png
```
You will see output file `out.png` in the same folder.

![result](https://raw.githubusercontent.com/aoowweenn/lbpcascade_animeface/master/figure/header_idolmaster_after.png)
![result2](https://raw.githubusercontent.com/aoowweenn/lbpcascade_animeface/master/figure/imas_all_after.png)
