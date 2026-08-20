// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenCanonicalStatusDeprecationProtocol.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnNodeDeprecatedSignature, FName, DeprecatedNodeID, FName, SupersedingNodeID, bool, bIsShadowVersioned);

/**
 * UAshenCanonicalStatusDeprecationProtocol
 *
 * Protocol enforcing Non-Destructive Deprecation (canonical_status: Deprecated + SUPERSEDES edge).
 */
UCLASS()
class ASHENOATH_API UAshenCanonicalStatusDeprecationProtocol : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|DeprecationProtocol")
	void DeprecateNodeNonDestructively(FName DeprecatedNodeID, FName SupersedingNodeID);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|DeprecationProtocol|Events")
	FOnNodeDeprecatedSignature OnNodeDeprecated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|DeprecationProtocol")
	int32 TotalDeprecatedNodesCount = 0;
};
