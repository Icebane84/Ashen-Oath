// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenDevilsBargainResolutionMasterBridge.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnResolutionBridgeSynchronizedSignature, FName, ResolutionTypeTag, bool, bMasterBridgeActive);

/**
 * UAshenDevilsBargainResolutionMasterBridge
 *
 * Master Orchestration bridge linking visual, haptic, acoustic, and soul state vectors for the prompt resolution (PRS-001-UI-006).
 */
UCLASS()
class ASHENOATH_API UAshenDevilsBargainResolutionMasterBridge : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ResolutionBridge")
	void SynchronizeResolutionPass(bool bSurrenderChosen);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ResolutionBridge|Events")
	FOnResolutionBridgeSynchronizedSignature OnResolutionBridgeSynchronized;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ResolutionBridge")
	bool bIsBridgeActive = false;
};
