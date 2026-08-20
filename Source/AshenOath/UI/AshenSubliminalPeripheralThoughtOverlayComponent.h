// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSubliminalPeripheralThoughtOverlayComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSubliminalThoughtFlickeredSignature, FText, ThoughtText, float, ScreenOpacity);

/**
 * UAshenSubliminalPeripheralThoughtOverlayComponent
 *
 * Component flashing single-frame diegetic thoughts ("Let go", "They die", "Take it") across peripheral vision (PRS-001-UI-006).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSubliminalPeripheralThoughtOverlayComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSubliminalPeripheralThoughtOverlayComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SubliminalThought")
	void FlickerSubliminalThought(FText ThoughtText);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SubliminalThought|Events")
	FOnSubliminalThoughtFlickeredSignature OnThoughtFlickered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SubliminalThought")
	int32 TotalThoughtsFlickered = 0;
};
