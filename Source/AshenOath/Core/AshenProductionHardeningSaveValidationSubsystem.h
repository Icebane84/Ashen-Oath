// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenProductionHardeningSaveValidationSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSaveValidationCompletedSignature, bool, bIsValid, uint32, Checksum);

/**
 * UAshenProductionHardeningSaveValidationSubsystem
 *
 * World Subsystem performing runtime CRC validation, save migration checks, and memory leak audits.
 */
UCLASS()
class ASHENOATH_API UAshenProductionHardeningSaveValidationSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ProductionHardening")
	bool ValidateSaveStateData(const TArray<uint8>& SaveBuffer);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ProductionHardening|Events")
	FOnSaveValidationCompletedSignature OnSaveValidationCompleted;
};
