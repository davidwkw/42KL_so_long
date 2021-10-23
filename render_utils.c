#include "so_long.h"

void	render_bg(t_data *img, t_data *bg)
{
	int w;
	int	h;
	int *src;
	int	*dst;

	src = (int *)bg->img;
	dst = (int *)img->img;
	h = -1;
	while (++h < img->height)
	{
		w = -1;
		while (++w < img->width)
		{
			if (dst[(h * img->size_line / (img->bpp / 8)) + w] == TRANS_INT)
				dst[(h * (img->size_line / (img->bpp / 8))) + w] = src[(h * (bg->size_line / (bg->bpp / 8))) + w];
		}
	}
}
