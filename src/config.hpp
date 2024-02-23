#ifndef CONFIG_HPP
#define CONFIG_HPP

constexpr unsigned short DEFAULT_PERCENT_OVERLAY_FILL = 80;


namespace xdash
{
    class Config
    {
        public:
        Config();

        virtual ~Config() = default;

        unsigned int getPercentOverlayFill() const;

        bool setPercentOverlayFill(const unsigned int value);

        private:
        unsigned short percentOverlayFill;
    };
}

#endif /* CONFIG_HPP */
