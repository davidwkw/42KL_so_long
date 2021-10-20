#include "so_long.h"

void	cache_image(void *mlx, t_data *img, char *path)
{
	img->addr = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	img->img = mlx_get_data_addr(img->addr, &img->bpp, &img->size_line, &img->endian);
}

void	cache_mirror_image(void *mlx, t_data *img, t_data *mirror)
{
	int		w;
	int		h;
	int		*dst;
	int		*src;

	mirror->addr = mlx_new_image(mlx, img->width, img->height);
	mirror->height = img->height;
	mirror->width = img->width;
	mirror->img = mlx_get_data_addr(mirror->addr, &mirror->bpp, &mirror->size_line, &mirror->endian);
	src = (int *)img->img;
	dst = (int *)mirror->img;
	h = -1;
	while (++h < img->height)
	{
		w = -1;
		while (++w < img->width)
			dst[w + (h * mirror->size_line / (mirror->bpp / 8))] = src[img->size_line + (h * img->size_line / (img->bpp / 8)) - w];
	}
}