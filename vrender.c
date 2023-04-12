#include <stdio.h>
#include <stdlib.h>
#include <vulkan/vulkan.h>


// defining a windows dimensions
//

const int WIDTH = 800;
const int HEIGHT = 600;


// the vulkan instance handle
VkInstance instance;

// vulkan device handle
VkDevice device;

// swap chain images
VkImage swapChainImages[3];

// swap chain image views
VkImageView swapChainImageViews[3];

// swap chain format
VkFormat swapChainImageFormat;

// swap chain extent
VkExtent2D swapChainExtent;

// function to create a vulkan instance

void createInstance() {
    // The Application info
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Vulken Renderer vrender";
    appInfo.applicationVersion = VK_MAKE_VERSION(0,0,1);
    appInfo.pEngineName = "No Engine here";
    appInfo.engineVersion = VK_MAKE_VERSION(0,0,1);
    appInfo.apiVersion = VK_API_VERSION_1_0;


    // instance create info
    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    // Create Vulkan instance
    VkResult result = vkCreateInstance(&createInfo, NULL, &instance);
    if (result != VK_SUCCESS) {
        printf("Failed to create vk instance\n");
        exit(1);
    }
}
