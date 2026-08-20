// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenHermeneuticFragmentationComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFragmentationPassExecutedSignature, FName, MemoryID, float, UncertaintyErosionAmount);

/**
 * UAshenHermeneuticFragmentationComponent
 *
 * Component executing the Fragmentation Pass ("Are you sure?", Whispering Void erosion exploiting uncertainty).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenHermeneuticFragmentationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenHermeneuticFragmentationComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|FragmentationPass")
	void ExecuteFragmentationPass(FName MemoryID, float ErosionAmount = 15.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|FragmentationPass|Events")
	FOnFragmentationPassExecutedSignature OnFragmentationExecuted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|FragmentationPass")
	float TotalErosionAccumulated = 0.0f;
};
