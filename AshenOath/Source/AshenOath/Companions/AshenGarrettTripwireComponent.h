// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettTripwireComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTripwireDeployed, FVector, StartPos, FVector, EndPos);

/**
 * UAshenGarrettTripwireComponent
 * Component deploying physical tension wires that trip sprinting enemies and stagger elites.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettTripwireComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenGarrettTripwireComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Combat")
	FOnTripwireDeployed OnTripwireDeployed;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	int32 ActiveTripwireCount = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool DeployTripwire(FVector AnchorA, FVector AnchorB);
};
