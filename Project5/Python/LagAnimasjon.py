import matplotlib.pyplot as plt
import matplotlib
from matplotlib.animation import FuncAnimation
import numpy as np
import pyarma as arma

U=arma.cx_cube()
sz=199
U.load(f"../Txt/U1{sz}.bin")
file=open(f"../Txt/U1{sz}.bin", "rb")
Ubs=arma.cube()
Ubs=arma.abs(U)
t_points = np.arange(0, Ubs.n_slices, 1)

# A function for a Gaussian that is travelling
# in the x direction and broadening as time passe
z_data_list = []
t_points = range(Ubs.n_slices)
x_points = range(Ubs.n_rows)
y_points = range(Ubs.n_rows)
n = Ubs.n_rows
for t in t_points:
    Mat = np.zeros((Ubs.n_rows, Ubs.n_rows))
    for i in range(n):
        for k in range(n):
            Mat[k][i] = Ubs[i, k, t]
    z_data_list.append(Mat)


#
# Now the list z_data_list contains a series of "frames" of z(x,y,t),
# where each frame can be plotted as a 2D image using imshow. Let's
# animate it!
#

# Some settings
fontsize = 12
t_min = t_points[0]
x_min, x_max = x_points[0], x_points[-1]
y_min, y_max = y_points[0], y_points[-1]

# Create figure
fig = plt.figure()
ax = plt.gca()

# Create a colour scale normalization according to the max z value in the first frame
norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=np.max(z_data_list[0]))

# Plot the first frame
img = ax.imshow(z_data_list[0], extent=[x_min,x_max,y_min,y_max], cmap=plt.get_cmap("viridis"), norm=norm)

# Axis labels
plt.xlabel("x", fontsize=fontsize)
plt.ylabel("y", fontsize=fontsize)
plt.xticks(fontsize=fontsize)
plt.yticks(fontsize=fontsize)

# Add a colourbar
cbar = fig.colorbar(img, ax=ax)
cbar.set_label("z(x,y,t)", fontsize=fontsize)
cbar.ax.tick_params(labelsize=fontsize)

# Add a text element showing the time
time_txt = plt.text(0.95, 0.95, "t = 0", color="white",
                    horizontalalignment="right", verticalalignment="top", fontsize=fontsize)

# Function that takes care of updating the z data and other things for each frame
def animation(i):
    # Normalize the colour scale to the current frame?
    norm = matplotlib.cm.colors.Normalize(vmin=0.0, vmax=np.max(z_data_list[i]))
    img.set_norm(norm)

    # Update z data
    img.set_data(z_data_list[i])

    # Update the time label
    current_time = t_min + i
    time_txt.set_text(f"t = {i:.3e}")
    plt.title(f't = {i}')
    return img

# Use matplotlib.animation.FuncAnimation to put it all together
anim = FuncAnimation(fig, animation, interval=1, frames=np.arange(0, len(z_data_list), 2), repeat=True, blit=0)

# Run the animation!
plt.show()

# # Save the animation
anim.save('../Images/animation.mp4', writer="ffmpeg", bitrate=-1, fps=30)
