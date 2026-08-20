// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMemoryFragmentCollectorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMemoryFragmentCollected, int32, TotalFragments);

/**
 * UAshenMemoryFragmentCollectorComponent
 * Component managing memory fragment pickups and identity restoration pulses.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryFragmentCollectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMemoryFragmentCollectorComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Soul")
	FOnMemoryFragmentCollected OnFragmentCollected;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Soul")
	int32 TotalReclaimedFragments = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void CollectMemoryFragment(FName FragmentID);
};
