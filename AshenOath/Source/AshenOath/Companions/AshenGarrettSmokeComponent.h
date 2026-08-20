// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettSmokeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSmokeCanisterDetonated, FVector, Location, float, Radius);

/**
 * UAshenGarrettSmokeComponent
 * Component creating dense alchemical smoke clouds breaking enemy line-of-sight.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettSmokeComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenGarrettSmokeComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Combat")
	FOnSmokeCanisterDetonated OnSmokeCanisterDetonated;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float SmokeRadius = 450.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	void DeploySmokeCanister(FVector DetonationLocation);
};
