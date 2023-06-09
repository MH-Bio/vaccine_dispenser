// UTouchCD.h
// ----------
//
// Since there are slight deviations in all touch screens you should run a
// calibration on your display module. Run the UTouch_Calibration sketch
// that came with this library and follow the on-screen instructions to
// update this file.
//
// Remember that is you have multiple display modules they will probably 
// require different calibration data so you should run the calibration
// every time you switch to another module.
// You can, of course, store calibration data for all your modules here
// and comment out the ones you dont need at the moment.
//

// These calibration settings works with my ER-TFTM050-5
// They MIGHT work on your display module, but you should run the
// calibration sketch anyway


#define CAL_X 0x0028CF61UL   //ER-TFTM050-5
#define CAL_Y 0x003F0EFDUL   //ER-TFTM050-5
#define CAL_S 0x8031F1DFUL   //ER-TFTM050-5