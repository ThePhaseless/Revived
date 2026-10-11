#pragma once

// Appends a line to LibRevive_<executable>.txt in the same data folder as the injector log.
// Meant for rare events like session creation, never for every frame.
void LogMessage(const char* format, ...);
