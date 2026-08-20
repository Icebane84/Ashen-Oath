// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOathbringerMindscapeComponent.generated.h"

UENUM(BlueprintType)
enum class EAshenSwordMorphState : uint8
{
	DisciplinedAegis,
	ShatteredRelic,
	BloodParasite,
	VoidMonolith
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSwordMorphStateChanged, EAshenSwordMorphState, NewState);

/**
 * UAshenOathbringerMindscapeComponent
 * Manages Oathbringer's real-time psychological Greatsword mesh morphing states and inner mindscape resonance.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerMindscapeComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenOathbringerMindscapeComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Oathbringer")
	FOnSwordMorphStateChanged OnSwordMorphStateChanged;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Oathbringer")
	EAshenSwordMorphState MorphState = EAshenSwordMorphState::DisciplinedAegis;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Oathbringer")
	void SetSwordMorphState(EAshenSwordMorphState NewState);
};
