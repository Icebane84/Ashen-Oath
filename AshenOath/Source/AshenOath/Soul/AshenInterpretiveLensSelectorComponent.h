// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenInterpretiveLensSelectorComponent.generated.h"

UENUM(BlueprintType)
enum class EAshenInterpretiveLens : uint8
{
	Grace           UMETA(DisplayName = "Lens of Grace"),
	Accountability  UMETA(DisplayName = "Lens of Accountability")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInterpretiveLensSelectedSignature, FName, MemoryID, EAshenInterpretiveLens, SelectedLens);

/**
 * UAshenInterpretiveLensSelectorComponent
 *
 * Component allowing the player to select Grace vs Accountability Lenses during Memory Weaving.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenInterpretiveLensSelectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenInterpretiveLensSelectorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|InterpretiveLens")
	void SelectLensForMemory(FName MemoryID, EAshenInterpretiveLens Lens);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|InterpretiveLens|Events")
	FOnInterpretiveLensSelectedSignature OnLensSelected;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|InterpretiveLens")
	EAshenInterpretiveLens CurrentActiveLens = EAshenInterpretiveLens::Grace;
};
