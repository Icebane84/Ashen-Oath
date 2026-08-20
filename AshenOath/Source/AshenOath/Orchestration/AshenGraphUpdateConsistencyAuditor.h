// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenGraphUpdateConsistencyAuditor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGUCADriftAuditedSignature, FName, NodeID, bool, bZeroDriftVerified);

/**
 * UAshenGraphUpdateConsistencyAuditor
 *
 * GUCA Subsystem auditing zero drift between engine runtime state and canonical PRS graph nodes.
 */
UCLASS()
class ASHENOATH_API UAshenGraphUpdateConsistencyAuditor : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|GUCA")
	bool AuditNodeDrift(FName NodeID, int32 RuntimeStateHash, int32 GraphNodeHash);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|GUCA|Events")
	FOnGUCADriftAuditedSignature OnGUCADriftAudited;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|GUCA")
	int32 TotalGUCAAuditsPassed = 0;
};
