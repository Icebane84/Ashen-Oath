// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 504: Ashen Production Hardening Save Validation Subsystem

#include "AshenProductionHardeningSaveValidationSubsystem.h"
#include "Misc/Crc.h"

void UAshenProductionHardeningSaveValidationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenProductionHardeningSaveValidationSubsystem: Initialized — Production Hardening Save Validation Subsystem ONLINE."));
}

bool UAshenProductionHardeningSaveValidationSubsystem::ValidateSaveStateData(const TArray<uint8>& SaveBuffer)
{
	const uint32 Checksum = FCrc::MemCrc32(SaveBuffer.GetData(), SaveBuffer.Num());
	const bool bIsValid = SaveBuffer.Num() > 0;

	OnSaveValidationCompleted.Broadcast(bIsValid, Checksum);

	UE_LOG(LogTemp, Warning, TEXT("UAshenProductionHardeningSaveValidationSubsystem: SAVE VALIDATION COMPLETED -> Valid: %s | CRC Checksum: 0x%08X (Bytes: %d)."),
		bIsValid ? TEXT("YES") : TEXT("NO"), Checksum, SaveBuffer.Num());

	return bIsValid;
}
