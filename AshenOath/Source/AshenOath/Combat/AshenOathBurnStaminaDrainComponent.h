// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOathBurnStaminaDrainComponent.generated.h"

/**
 * UAshenOathBurnStaminaDrainComponent
 * Component applying continuous -2.0/s stamina drain when OathBurden >= 1.0f; locks stamina recovery until next Heartstone.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathBurnStaminaDrainComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenOathBurnStaminaDrainComponent();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	bool bOathBurnActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float StaminaDrainPerSecond = 2.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	void SetOathBurnState(bool bActive);
};
