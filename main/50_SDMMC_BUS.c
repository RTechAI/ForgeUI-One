// ============================================================
// ForgeUI SDMMC Shared Bus Layer
// ============================================================
//
// Reserved for future shared SDMMC ownership layer.
//
// Current V1 Status:
//
// - direct SD init path currently used
// - hosted WiFi path proven stable
// - no shared arbitration layer required yet
//
// Current Proven Rule:
//
//   WiFi first
//   -> SD second
//
// Future Direction:
//
// - shared SDMMC ownership
// - transport arbitration
// - hosted WiFi / SD coordination
// - shared bus locking
// - storage/network scheduling
//
// ============================================================