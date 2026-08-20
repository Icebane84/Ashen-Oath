// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenSpiritualScarringHealthStainSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSpiritualStainAppliedSignature, float, TotalStainPercent, float, LockedMaxHealth);

/**
 * UAshenSpiritualScarringHealthStainSubsystem
 *
 * Subsystem locking permanent max health/stamina behind black UI Stain (The Cost / Spiritual Scarring, PRS-001 Combat Blueprint).
 */
UCLASS()
class ASHENOATH_API UAshenSpiritualScarringHealthStainSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SpiritualScarring")
	void ApplySpiritualStain(float DeltaStainPercent);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SpiritualScarring")
	void CleanseSpiritualStain(float CleansePercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SpiritualScarring|Events")
	FOnSpiritualStainAppliedSignature OnStainApplied;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SpiritualScarring")
	float ActiveStainPercent = 0.0f;
};
