#include "so_long.h"

void	calc_offsets(t_data *img)
{
	int w;
	int	h;
	int	*img_data;

	img_data = (int *)img->img;
	h = -1;
	while (++h < img->height)
	{
		w = -1;
		while (++w < img->width)
		{
			if (!img->offsets.top && img_data[(h * img->size_line / (img->bpp / 8)) + w] != TRANS_INT)
			{
				img->offsets.top = h;
				img->offsets.left = w;
			}
			else if (img_data[(h * img->size_line / (img->bpp / 8)) + w] != TRANS_INT && w < img->offsets.left)
				img->offsets.left = w;
			if (img_data[(h * img->size_line / (img->bpp / 8)) + w] != TRANS_INT && h > img->offsets.bottom)
				img->offsets.bottom = h;
		}
	}
}