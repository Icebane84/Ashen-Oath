// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenShatteredVirtueSystemSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVirtueFractureChangedSignature, FName, FractureID, bool, bIsActive);

/**
 * UAshenShatteredVirtueSystemSubsystem
 *
 * World Subsystem managing long-term trauma flaws ("Virtue Fractures") like Survivor's Guilt or Betrayal's Scar.
 */
UCLASS()
class ASHENOATH_API UAshenShatteredVirtueSystemSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ShatteredVirtue")
	void InflictVirtueFracture(FName FractureID);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ShatteredVirtue")
	void HealVirtueFractureViaRedemption(FName FractureID);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ShatteredVirtue|Events")
	FOnVirtueFractureChangedSignature OnVirtueFractureChanged;

private:
	TSet<FName> ActiveFractures;
};
