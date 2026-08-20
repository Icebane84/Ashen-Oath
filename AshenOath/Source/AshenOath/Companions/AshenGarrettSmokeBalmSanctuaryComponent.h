// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettSmokeBalmSanctuaryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSmokeBalmSanctuaryDeployedSignature, FVector, DeployedLocation, float, SanctuaryRadius);

/**
 * UAshenGarrettSmokeBalmSanctuaryComponent
 *
 * Component deploying Garrett's Smoke Balm sanctuary fields during high-entropy combat encounters (PRS-001 Garrett Slice).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettSmokeBalmSanctuaryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettSmokeBalmSanctuaryComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|GarrettSmokeBalm")
	void DeploySmokeBalmSanctuary(FVector TargetLocation, float CloudRadius = 500.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|GarrettSmokeBalm|Events")
	FOnSmokeBalmSanctuaryDeployedSignature OnSmokeBalmDeployed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|GarrettSmokeBalm")
	int32 TotalSmokeBalmsDeployed = 0;
};
