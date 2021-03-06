#ifndef WS2812INTERFACE_H
#define WS2812INTERFACE_H

#include <stdint.h>

//------------------------------ structs ------------------------------
/** \brief struct for holding the color value
 *
 * its in the wrong order (GRB) because usually WS2812 expecting the data in this order
 *
 */
struct RGBColor
{
    uint8_t G;
    uint8_t R;
    uint8_t B;

    RGBColor() : G(0), R(0), B(0)
    {    }

    RGBColor(uint8_t r, uint8_t g, uint8_t b) : G(g), R(r), B(b)
    {    }


};

/** \brief Interface class for WS2812
 *  It already implements the LED buffer and setting colors
 *
 */
class IPixelDisplay
{



public:
    // ----------------------------- USER DEFINED CONSTANTS -----------------------------
    /** \brief the exact amount of Pixel you have in the stripe
     *
     */
    const uint16_t NR_PIXEL;

    /** \brief the real number of LEDs, because there is one for each color
     *
     */
    const uint16_t NR_LEDS; //amount of pixel * amount of color (RGB = 3)

    /** \brief the Constructor
     *
     * \param set @NR_PIXEL and reserve RAm for Pixel buffer
     *
     */
    IPixelDisplay(uint16_t _nr_pixel);

    /** \brief the Destruktor freeing the buffer
     *
     *
     */
    ~IPixelDisplay();
// ----------------------------- functions -----------------------------
    /** \brief Init the WS2812 driver hardware and framebuffer
     *
     */
    virtual void init(void)=0;

    /** \brief do one update of the whole stripe
     *
     * this method will start the transforamtion from the Pixel buffer to the framebuffer
     * and sending the data to the WS2812 controller
     *
     * this method will return immediately, but sending the data to Ws2812 could take longer
     * so calling again this method while data are still sending, will do nothing
     * so check out the return value of this method
     *
     * \return true if update is accepted and sending of new data started, false when is still busy with sending previous data
     */
    virtual bool update(void)=0;

// ----------------------------- graphics -----------------------------
    /** \brief set the color of one specific Pixel
     *
     * \param pixel number 0 - @NR_PIXEL
     * \param c the color in @RGBColor struct
     *
     */
    void setPixel(uint8_t pixel, const RGBColor &c);

    /** \brief set the color of all Pixel
     *
     * \param c the color in @RGBColor struct
     *
     */
    void setAllPixel(const RGBColor &c);

    /** \brief clear all Pixel
     *
     * set color to 0 for all pixel
     *
     */
    void clearAllPixel();


    /** \brief The Pixel buffer
     *
     */
    RGBColor *Pixel;

};
#endif //WS2812INTERFACE_H
