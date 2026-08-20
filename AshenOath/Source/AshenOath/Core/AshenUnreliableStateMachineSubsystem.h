// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenUnreliableStateMachineSubsystem.generated.h"

UENUM(BlueprintType)
enum class EAshenInterfaceMode : uint8
{
	DiegeticOnly       UMETA(DisplayName = "Diegetic Only (Living World)"),
	AbstractTactical   UMETA(DisplayName = "Abstract Tactical (Overlay)"),
	FalseConfidence    UMETA(DisplayName = "False Confidence (Deceptive Interface)")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInterfaceModeChangedSignature, EAshenInterfaceMode, NewMode);

/**
 * UAshenUnreliableStateMachineSubsystem
 *
 * World Subsystem governing Diegetic vs Abstract UI layer switching and False Confidence deceptive states (UMB-SYS-005).
 */
UCLASS()
class ASHENOATH_API UAshenUnreliableStateMachineSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UnreliableUI")
	void SetInterfaceMode(EAshenInterfaceMode NewMode);

	UFUNCTION(BlueprintPure, Category = "AshenOath|UnreliableUI")
	EAshenInterfaceMode GetCurrentInterfaceMode() const { return CurrentInterfaceMode; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|UnreliableUI|Events")
	FOnInterfaceModeChangedSignature OnInterfaceModeChanged;

private:
	EAshenInterfaceMode CurrentInterfaceMode = EAshenInterfaceMode::DiegeticOnly;
};
