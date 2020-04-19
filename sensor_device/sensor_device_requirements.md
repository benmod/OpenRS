# Requirements  
  
Those requirements are based on the analysis of different commercially available sensors as well as medical literature around ventilation. We made an effort to distinguish between what would be an ideal and what would be still acceptable for the use case. 
  
## Key Requirements  
 
 - Proximal Flow measurement
 - Proximal Pressure measurement
 - Compatibility with standard connectors used in BVMs and ventilators (see **[ISO 5356-1:2015](https://www.iso.org/standard/54851.html?browse=tc)**)
 - Affordability (manufacturing cost <10$)
 - Ease of manufacturing (only 3D printing and common parts)

## Functional Parameters

|Parameter|Minimum Viable Value|Ideal Value|
|--|--|--|
| Pressure Range | 0 - 2 kPa (0 - 20 cmH2O) | -4 - +4 kPa (-42 - +41 cmH2O) | 
| Pressure Resolution | 0.2 kPa (2 cmH2O) | 0.1 kPa (1 cmH2O) |
| Pressure Accuracy | <10% m.v | <5% m.v |
| Pressure Noise Level | <5% m.v | <2.5% m.v |
| Pressure Update Time | <100 ms | <10 ms |
| Flow Range | 0 - 100 slm | -250 - +250 slm |
| Flow Resolution | 1 slm | 0.2 slm |
| Flow Offset | 2 slm | 0.2 slm |
| Flow Accuracy | <20% m.v | <5% m.v |
| Flow Noise Level | <5% m.v | <2.5% m.v |
| Flow Update Time | <100 ms | <10 ms |
| Pressure drop | <1 kPa (10 cmH2O) | <0.5 kPa (5 cmH2O) |
| Dead Space | <25 mL | <10 mL |

**m.v:** measured value  
**slm:** standard liter per minute

## Operating Parameters
|Parameter|Minimum Viable Value|Ideal Value|
|--|--|--|
| Operating Temperature | +5 - +35 °C | 0 - +50 °C |
| Operating Humidity (relative) | 10 - 95 % (non-condensing) | 10 - 95 % (non-condensing) |
| Media Compatibility | Air, N2, O2 | Air, N2, O2, other non- aggressive gases |


