// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenCANAnchorRegistrySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCANAnchorRegisteredSignature, FName, CANAnchorID, FString, NuanceConflictSummary);

/**
 * UAshenCANAnchorRegistrySubsystem
 *
 * Subsystem registering Canonical Anchors of Nuance (CANs) such as FaithVsDoubt, TriageBurden, GlassShieldProtocol, EmpathicBurnout.
 */
UCLASS()
class ASHENOATH_API UAshenCANAnchorRegistrySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CANAnchors")
	void RegisterCANAnchor(FName CANAnchorID, FString ConflictSummary);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CANAnchors|Events")
	FOnCANAnchorRegisteredSignature OnCANRegistered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|CANAnchors")
	TArray<FName> RegisteredCANIDs;
};
