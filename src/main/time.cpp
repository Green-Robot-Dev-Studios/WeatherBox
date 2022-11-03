#include <ezTime.h>

Timezone set_time(){
    waitForSync();
    // updateNTP();
        
    Timezone Toronto;
	  Toronto.setLocation("America/New_York");
    Serial.println("Toronto Time: " + Toronto.dateTime());
    Serial.println("Done initialization");

    return Toronto;
}

//int get_angle()

