// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenDevilsBargainChillingSilenceSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChillingSilenceStateChangedSignature, bool, bIsChillingSilenceActive, FText, PostSurrenderWhisper);

/**
 * UAshenDevilsBargainChillingSilenceSubsystem
 *
 * Subsystem executing the late-game Chilling Silence parasite protocol (PRS-001 Combat Blueprint V5.0).
 */
UCLASS()
class ASHENOATH_API UAshenDevilsBargainChillingSilenceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ChillingSilence")
	void EvaluateChillingSilenceProtocol(int32 TotalSurrendersToDarkMode);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ChillingSilence|Events")
	FOnChillingSilenceStateChangedSignature OnChillingSilenceStateChanged;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ChillingSilence")
	bool bIsChillingSilenceActive = false;
};
