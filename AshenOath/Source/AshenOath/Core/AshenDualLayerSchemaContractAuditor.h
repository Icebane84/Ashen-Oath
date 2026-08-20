// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenDualLayerSchemaContractAuditor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSchemaContractAuditedSignature, FName, StatName, bool, bIsParityMaintained);

/**
 * UAshenDualLayerSchemaContractAuditor
 *
 * Subsystem enforcing Zod <-> C++ stat parity audit across runtime schemas and C++ components.
 */
UCLASS()
class ASHENOATH_API UAshenDualLayerSchemaContractAuditor : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SchemaAudit")
	bool AuditStatParity(FName StatName, float ZodSchemaValue, float CPlusPlusValue);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SchemaAudit|Events")
	FOnSchemaContractAuditedSignature OnSchemaAudited;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SchemaAudit")
	int32 TotalParityAudits = 0;
};
