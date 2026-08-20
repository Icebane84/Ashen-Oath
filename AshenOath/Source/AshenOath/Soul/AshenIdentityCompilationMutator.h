// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenIdentityCompilationMutator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnIdentityCompilationMutatedSignature, float, NewIntegrationDebt, float, NewResolve);

/**
 * UAshenIdentityCompilationMutator
 *
 * Subsystem mutating FSoulStateVector based on completed Integrative vs Fragmentation passes.
 */
UCLASS()
class ASHENOATH_API UAshenIdentityCompilationMutator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|IdentityCompilation")
	void MutateSoulStateFromPassResult(bool bIntegrativePassSuccess, float DeltaWeight);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|IdentityCompilation|Events")
	FOnIdentityCompilationMutatedSignature OnIdentityMutated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|IdentityCompilation")
	float ActiveIntegrationDebt = 0.5f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|IdentityCompilation")
	float ActiveResolve = 0.8f;
};
