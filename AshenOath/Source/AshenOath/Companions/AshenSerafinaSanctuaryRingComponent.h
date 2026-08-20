// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaSanctuaryRingComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanctuaryRingDeployed, FVector, Location, float, Radius);

/**
 * UAshenSerafinaSanctuaryRingComponent
 * Deploys consecrated ward ring calming Kaelen's hallucinations and debuffing foes.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaSanctuaryRingComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSerafinaSanctuaryRingComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Sanctuary")
	FOnSanctuaryRingDeployed OnSanctuaryRingDeployed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Sanctuary")
	float SanctuaryRadius = 550.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Sanctuary")
	bool ManifestSanctuaryRing(FVector GroundLocation);
};
