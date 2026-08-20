// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenConsecratedGroundSanctuaryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConsecratedGroundActiveSignature, FVector, GroundCenter, float, HealPerSecond);

/**
 * UAshenConsecratedGroundSanctuaryComponent
 *
 * Component creating holy sanctuary healing ground pools.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenConsecratedGroundSanctuaryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenConsecratedGroundSanctuaryComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ConsecratedGround")
	void SpawnConsecratedGroundPool(FVector GroundCenter, float HealPerSecond = 20.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ConsecratedGround|Events")
	FOnConsecratedGroundActiveSignature OnGroundActive;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ConsecratedGround")
	bool bIsGroundActive = false;
};
