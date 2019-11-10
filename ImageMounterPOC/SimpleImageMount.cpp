#include <sys/mount.h>  //mount
#include <sys/ioctl.h>  //ioctl
#include <sys/stat.h>   //open
#include <linux/loop.h> //LOOP_SET_FD
#include <fcntl.h>      //open
#include <cstdio>       // declaration of ::fileno
#include <cstdint>      //int32_t
#include <sstream>      //std::stringstream

#include <string>

constexpr char IMAGE_NAME[] = "image.img";       //of course we need this file to be present in same folder as built tool
constexpr char MOUNT_POINT[] = "/tmp/image_mnt"; //of course we need this folder already created
constexpr char FILESYSTEM_TYPE[] = "ext4";
constexpr char DEV_LOOP_CONTROL[] = "/dev/loop-control";
constexpr char DEV_LOOP_PREFIX[] = "/dev/loop";
constexpr int32_t MOUNT_FLAGS = MS_RDONLY;

int main()
{
    const auto loop_control = std::fopen(DEV_LOOP_CONTROL, "r");
    const auto loop_control_fd = fileno(loop_control);
    const auto devnr = ioctl(loop_control_fd, LOOP_CTL_GET_FREE);
    std::stringstream loopname;
    loopname << DEV_LOOP_PREFIX << devnr;
    const auto loop_device_name = loopname.str();
    const auto loop_device = std::fopen(loop_device_name.c_str(), "r");
    const auto loop_device_fd = fileno(loop_device);
    const auto image = std::fopen(IMAGE_NAME, "r");
    const auto image_fd = fileno(image);
    //Associate the loop device with the open file whose file descriptor is passed as the (third) ioctl(2) argument.
    ioctl(loop_device_fd, LOOP_SET_FD, image_fd);
    const auto result = mount(loop_device_name.c_str(), MOUNT_POINT, FILESYSTEM_TYPE, MOUNT_FLAGS, NULL);
    ioctl(loop_device_fd, LOOP_CLR_FD, 0);
    return result;
}