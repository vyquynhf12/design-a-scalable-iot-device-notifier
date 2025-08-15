#include <string>
#include <vector>
#include <map>

class IoTDevice {
public:
    std::string id;
    std::string name;
    std::string type;
    std::string ipAddress;
    int notificationThreshold;

    IoTDevice(std::string id, std::string name, std::string type, std::string ipAddress, int notificationThreshold) :
        id(id), name(name), type(type), ipAddress(ipAddress), notificationThreshold(notificationThreshold) {}
};

class Notifier {
public:
    std::vector<IoTDevice*> devices;
    std::map<std::string, int> notificationCounts;

    void addDevice(IoTDevice* device) {
        devices.push_back(device);
    }

    void notify(IoTDevice* device) {
        notificationCounts[device->id]++;
        if (notificationCounts[device->id] >= device->notificationThreshold) {
            // send notification (e.g., email, SMS, etc.)
            std::cout << "Notification sent for device " << device->name << " (" << device->id << ")" << std::endl;
            notificationCounts[device->id] = 0;
        }
    }
};

int main() {
    Notifier notifier;

    IoTDevice device1("D001", "Temperature Sensor", "temperature", "192.168.0.100", 5);
    IoTDevice device2("D002", "Humidity Sensor", "humidity", "192.168.0.101", 3);
    IoTDevice device3("D003", "Motion Sensor", "motion", "192.168.0.102", 10);

    notifier.addDevice(&device1);
    notifier.addDevice(&device2);
    notifier.addDevice(&device3);

    // simulate IoT device data
    for (int i = 0; i < 15; i++) {
        if (i % 3 == 0) {
            notifier.notify(&device1);
        }
        if (i % 5 == 0) {
            notifier.notify(&device2);
        }
        if (i % 10 == 0) {
            notifier.notify(&device3);
        }
    }

    return 0;
}