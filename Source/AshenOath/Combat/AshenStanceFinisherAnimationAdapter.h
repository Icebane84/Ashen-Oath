// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenStanceFinisherAnimationAdapter.generated.h"

/**
 * UAshenStanceFinisherAnimationAdapter
 * Adapter triggering stance-tailored execution anim montages (Razor, Sentinel, Weaver).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenStanceFinisherAnimationAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenStanceFinisherAnimationAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool PlayStanceFinisherMontage(FName StanceName);
};
