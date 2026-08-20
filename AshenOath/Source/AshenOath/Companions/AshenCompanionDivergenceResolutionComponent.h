// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionDivergenceResolutionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDivergenceResolvedSignature, FName, CompanionID, bool, bReconciled);

/**
 * UAshenCompanionDivergenceResolutionComponent
 *
 * Component enabling reconciliation dialogue rituals or duel encounters when companion divergence triggers.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionDivergenceResolutionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionDivergenceResolutionComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|DivergenceResolution")
	void ResolveCompanionDivergence(FName CompanionID, bool bReconcileSuccess);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|DivergenceResolution|Events")
	FOnDivergenceResolvedSignature OnDivergenceResolved;
};
