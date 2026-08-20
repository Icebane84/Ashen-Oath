# High-Performance Cognitive Architecture for Ashen Oath

## Bridging Soulslike Game Design with Unreal Engine C++ — Corrected & Complete

This spec integrates cognitive AI mechanics into `Ashen Oath`'s C++ codebase,
mapping FromSoftware-style combat philosophy onto `CORE.CODEX.PhoenixSchema`
and UE 5.8. This revision resolves every compile-blocking bug, race
condition, and modularity gap identified across review passes, and adds the
missing threat-perception producer.

---

## 1. Architectural Parity with FromSoftware Design

Two governing principles: **Tactical Readability** (players can recognize
and react to telegraphs) and **Reactive Fairness** (AI "input reading" is
probabilistic and stamina-gated, not frame-perfect).

### Telegraphing vulnerability

$$O_p(t)=\max\left(0,1-\frac{|t-T_{ideal}|}{\sigma}\right)$$

### Dynamic Input Reading

$$P_{react}=P_{base}\cdot(1-\phi_{stamina})\cdot\omega_{aggression}\cdot e^{-\lambda\cdot d}$$

### LAW-041 Entropy Decay (Emergent Choice)

$$R(S'_j)=R_{base}(S'_j)\cdot(1-\gamma\cdot N_{recent})$$

---

## 2. `FStateTreeTask_EvaluateAction`

**Fixes applied:** targets resolved via threat table (no singular player
lookup — multiplayer-safe); `CognitiveComp` cached instead of re-resolved via
`FindComponentByClass` every tick; punish-trigger tag/range/multiplier
promoted from hardcoded literals to designer-configurable instance data.

```cpp
// FStateTreeTask_EvaluateAction.h
// Copyright Phoenix Protocol. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "GameplayTagContainer.h"
#include "FStateTreeTask_EvaluateAction.generated.h"

class UAICognitiveComponent;

USTRUCT(BlueprintType)
struct ASHENOATH_API FStateTreeTask_EvaluateActionInstanceData
{
 GENERATED_BODY()

 UPROPERTY(EditAnywhere, Category = "Input")
 FGameplayTag ActionTypeTag = FGameplayTag();

 UPROPERTY(EditAnywhere, Category = "Input")
 float BaseUtility = 0.5f;

 UPROPERTY(EditAnywhere, Category = "Input")
 float PreferredRange = 300.0f;

 // Punish-window configuration — was hardcoded in Tick(); now per-archetype tunable.
 UPROPERTY(EditAnywhere, Category = "Punish Window")
 FGameplayTag PunishTriggerTag; // e.g. Gameplay.Action.Heal

 UPROPERTY(EditAnywhere, Category = "Punish Window")
 float PunishRange = 800.0f;

 UPROPERTY(EditAnywhere, Category = "Punish Window")
 float PunishMultiplier = 2.5f;

 UPROPERTY(EditAnywhere, Category = "Entropy")
 float EntropyWindowSeconds = 15.0f;

 UPROPERTY(EditAnywhere, Category = "Entropy")
 float EntropyGamma = 0.4f;

 UPROPERTY(EditAnywhere, Category = "Output")
 float OutCalculatedUtility = 0.0f;

 // Resolved once in EnterState, reused every Tick — avoids a per-frame
 // FindComponentByClass reflection scan across every active agent.
 UPROPERTY(Transient)
 TWeakObjectPtr<UAICognitiveComponent> CachedCognitiveComp;
};

/**
 * @struct FStateTreeTask_EvaluateAction
 * @brief StateTree task executing Markovian utility and input-reading evaluation.
 *
 * NOTE (open item, not auto-enforceable in this file): ActionTypeTag here and
 * AbilityTag on any co-resident FStateTreeTask_ExecuteAbility must match for
 * LAW-041 entropy decay to function. Recommend adding a per-state tag-parity
 * check to the AOP-MECS-TOOLKIT auditor pipeline rather than relying on
 * designer discipline — a mismatch fails silently (decay never applies, no
 * error surfaced).
 */
USTRUCT(BlueprintType, meta = (DisplayName = "Ashen Action Evaluation"))
struct ASHENOATH_API FStateTreeTask_EvaluateAction final : public FStateTreeTaskCommonBase
{
 GENERATED_BODY()

 typedef FStateTreeTask_EvaluateActionInstanceData FInstanceDataType;

 virtual const UScriptStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }

 virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
 virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
};
```

```cpp
// FStateTreeTask_EvaluateAction.cpp
// Copyright Phoenix Protocol. All rights reserved.
#include "FStateTreeTask_EvaluateAction.h"
#include "StateTreeExecutionContext.h"
#include "AIController.h"
#include "AbilitySystemGlobals.h"
#include "AbilitySystemComponent.h"
#include "AshenCharacterInterface.h"
#include "AshenOath_StaminaComponent.h"
#include "UAICognitiveComponent.h"

EStateTreeRunStatus FStateTreeTask_EvaluateAction::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
 FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

 // Fixed: Cast() on a value, not &Context.GetOwner() (GetOwner() returns
 // AActor* by value; taking its address was a compile error).
 const AAIController* AIController = Cast<AAIController>(Context.GetOwner());
 if (const APawn* AIPawn = AIController ? AIController->GetPawn() : nullptr)
 {
  InstanceData.CachedCognitiveComp = AIPawn->FindComponentByClass<UAICognitiveComponent>();
 }

 return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FStateTreeTask_EvaluateAction::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
 FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

 AAIController* AIController = Cast<AAIController>(Context.GetOwner());
 if (!AIController)
 {
  return EStateTreeRunStatus::Failed;
 }

 APawn* AIPawn = AIController->GetPawn();
 if (!AIPawn)
 {
  return EStateTreeRunStatus::Failed;
 }

 // Lazy re-resolve only if EnterState's cache came up empty (e.g. component
 // added after this state's EnterState already ran) — still avoids the
 // steady-state per-tick cost in the common case.
 if (!InstanceData.CachedCognitiveComp.IsValid())
 {
  InstanceData.CachedCognitiveComp = AIPawn->FindComponentByClass<UAICognitiveComponent>();
 }

 UAICognitiveComponent* CognitiveComp = InstanceData.CachedCognitiveComp.Get();
 if (!CognitiveComp)
 {
  return EStateTreeRunStatus::Failed;
 }

 APawn* TargetActor = CognitiveComp->GetPrimaryThreatTarget();
 if (!TargetActor)
 {
  // No live threat — genuinely empty table now that zero-score
  // candidates are dropped at the source (see ThreatPerceptionComponent).
  InstanceData.OutCalculatedUtility = 0.0f;
  return EStateTreeRunStatus::Failed;
 }

 UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(TargetActor);
 float InputReadingModifier = 1.0f;

 if (TargetASC && InstanceData.PunishTriggerTag.IsValid() &&
     TargetASC->HasMatchingGameplayTag(InstanceData.PunishTriggerTag))
 {
  const float Dist = FVector::Dist(AIPawn->GetActorLocation(), TargetActor->GetActorLocation());
  if (Dist < InstanceData.PunishRange)
  {
   InputReadingModifier = InstanceData.PunishMultiplier;
  }
 }

 float StaminaFactor = 1.0f;
 if (AIPawn->Implements<UAshenCharacterInterface>())
 {
  const UAshenOath_StaminaComponent* StaminaComp = IAshenCharacterInterface::Execute_GetStaminaComponent(AIPawn);
  if (StaminaComp)
  {
   StaminaFactor = StaminaComp->GetCurrentStamina() / FMath::Max(1.0f, StaminaComp->GetMaxStamina());
  }
 }

 const float CurrentDistance = FVector::Dist(AIPawn->GetActorLocation(), TargetActor->GetActorLocation());
 const float DistanceDelta = FMath::Abs(CurrentDistance - InstanceData.PreferredRange);
 const float DistanceScore = 1.0f / (1.0f + (DistanceDelta * 0.002f));

 const int32 RecentExecutions = CognitiveComp->GetRecentExecutionCount(InstanceData.ActionTypeTag, InstanceData.EntropyWindowSeconds);
 const float EntropyDecay = FMath::Max(0.1f, 1.0f - (InstanceData.EntropyGamma * RecentExecutions));

 InstanceData.OutCalculatedUtility = InstanceData.BaseUtility * DistanceScore * StaminaFactor * InputReadingModifier * EntropyDecay;

 return EStateTreeRunStatus::Running;
}
```

---

## 3. `FStateTreeTask_ExecuteAbility`

**Fixes applied:** `[0]` index on the matched-abilities array (was assigning
a `TArray` directly to a single handle — compile error); delegate lambdas
given proper `[...]` capture lists (previously missing on all instances);
delegate now bound **before** `TryActivateAbility`, not after, closing a race
where synchronously-completing abilities could end before anything is
listening; `AIController`/`ASC`/`CognitiveComp` cached per-state instead of
re-resolved in every callback.

```cpp
// FStateTreeTask_ExecuteAbility.h
// Copyright Phoenix Protocol. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "GameplayTagContainer.h"
#include "GameplayAbilitySpecHandle.h"
#include "FStateTreeTask_ExecuteAbility.generated.h"

class UAICognitiveComponent;

USTRUCT(BlueprintType)
struct ASHENOATH_API FStateTreeTask_ExecuteAbilityInstanceData
{
 GENERATED_BODY()

 UPROPERTY(EditAnywhere, Category = "Input")
 FGameplayTag AbilityTag = FGameplayTag();

 UPROPERTY(Transient)
 FGameplayAbilitySpecHandle ActiveAbilityHandle;

 UPROPERTY(Transient)
 FDelegateHandle AbilityEndedDelegateHandle;

 UPROPERTY(Transient)
 TWeakObjectPtr<UAICognitiveComponent> CachedCognitiveComp;
};

/**
 * @struct FStateTreeTask_ExecuteAbility
 * @brief Triggers a GAS ability and awaits lifecycle completion via a
 * decoupled side-channel on UAICognitiveComponent (game-thread only —
 * not a thread-safety guarantee, just an ordering convenience given GAS
 * delegates and StateTree ticks both run on the game thread).
 */
USTRUCT(BlueprintType, meta = (DisplayName = "Ashen Execute GAS Ability"))
struct ASHENOATH_API FStateTreeTask_ExecuteAbility final : public FStateTreeTaskCommonBase
{
 GENERATED_BODY()

 typedef FStateTreeTask_ExecuteAbilityInstanceData FInstanceDataType;

 virtual const UScriptStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }

 virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
 virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
 virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
};
```

```cpp
// FStateTreeTask_ExecuteAbility.cpp
// Copyright Phoenix Protocol. All rights reserved.
#include "FStateTreeTask_ExecuteAbility.h"
#include "StateTreeExecutionContext.h"
#include "AIController.h"
#include "AbilitySystemGlobals.h"
#include "AbilitySystemComponent.h"
#include "UAICognitiveComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogAshenAI, Log, All);

EStateTreeRunStatus FStateTreeTask_ExecuteAbility::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
 FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

 AAIController* AIController = Cast<AAIController>(Context.GetOwner());
 if (!AIController)
 {
  return EStateTreeRunStatus::Failed;
 }

 APawn* AIPawn = AIController->GetPawn();
 if (!AIPawn)
 {
  return EStateTreeRunStatus::Failed;
 }

 UAICognitiveComponent* CognitiveComp = AIPawn->FindComponentByClass<UAICognitiveComponent>();
 UAbilitySystemComponent* ASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(AIPawn);
 if (!CognitiveComp || !ASC)
 {
  return EStateTreeRunStatus::Failed;
 }
 InstanceData.CachedCognitiveComp = CognitiveComp;

 TArray<FGameplayAbilitySpecHandle> MatchingAbilities;
 ASC->FindAllAbilitiesWithTags(MatchingAbilities, FGameplayTagContainer(InstanceData.AbilityTag));

 if (MatchingAbilities.Num() == 0)
 {
  return EStateTreeRunStatus::Failed;
 }
 if (MatchingAbilities.Num() > 1)
 {
  UE_LOG(LogAshenAI, Warning, TEXT("Multiple abilities matched tag %s — picking first"), *InstanceData.AbilityTag.ToString());
 }

 // Fixed: was `InstanceData.ActiveAbilityHandle = MatchingAbilities;` —
 // assigning a TArray to a single FGameplayAbilitySpecHandle, compile error.
 InstanceData.ActiveAbilityHandle = MatchingAbilities[0];
 CognitiveComp->ClearAbilityCompletion(InstanceData.ActiveAbilityHandle);

 // Fixed: bind BEFORE activating. TryActivateAbility can activate AND end
 // a synchronously-completing ability within this single call — binding
 // after activation risks missing that OnAbilityEnded fire entirely,
 // leaving the StateTree task stuck in Running forever.
 TWeakObjectPtr<UAICognitiveComponent> WeakCognitive(CognitiveComp);
 const FGameplayAbilitySpecHandle TargetHandle = InstanceData.ActiveAbilityHandle;

 // Fixed: lambda was missing its [] capture list (compile error).
 InstanceData.AbilityEndedDelegateHandle = ASC->OnAbilityEnded.AddLambda(
  [WeakCognitive, TargetHandle](const FAbilityEndedData& EndedData)
  {
   if (WeakCognitive.IsValid() && EndedData.AbilitySpecHandle == TargetHandle)
   {
    WeakCognitive->SetAbilityCompleted(TargetHandle);
   }
  }
 );

 if (!ASC->TryActivateAbility(InstanceData.ActiveAbilityHandle))
 {
  ASC->OnAbilityEnded.Remove(InstanceData.AbilityEndedDelegateHandle);
  InstanceData.AbilityEndedDelegateHandle.Reset();
  return EStateTreeRunStatus::Failed;
 }

 return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FStateTreeTask_ExecuteAbility::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
 const FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

 const UAICognitiveComponent* CognitiveComp = InstanceData.CachedCognitiveComp.Get();
 if (!CognitiveComp)
 {
  return EStateTreeRunStatus::Failed;
 }

 if (CognitiveComp->IsAbilityCompleted(InstanceData.ActiveAbilityHandle))
 {
  return EStateTreeRunStatus::Succeeded;
 }

 return EStateTreeRunStatus::Running;
}

void FStateTreeTask_ExecuteAbility::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
 FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

 AAIController* AIController = Cast<AAIController>(Context.GetOwner());
 APawn* AIPawn = AIController ? AIController->GetPawn() : nullptr;
 UAbilitySystemComponent* ASC = AIPawn ? UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(AIPawn) : nullptr;

 if (ASC && InstanceData.AbilityEndedDelegateHandle.IsValid())
 {
  ASC->OnAbilityEnded.Remove(InstanceData.AbilityEndedDelegateHandle);
  InstanceData.AbilityEndedDelegateHandle.Reset();
 }

 if (UAICognitiveComponent* CognitiveComp = InstanceData.CachedCognitiveComp.Get())
 {
  CognitiveComp->ClearAbilityCompletion(InstanceData.ActiveAbilityHandle);
  CognitiveComp->RecordAction(InstanceData.AbilityTag);
 }

 InstanceData.ActiveAbilityHandle = FGameplayAbilitySpecHandle();
}
```

---

## 4. `UAICognitiveComponent`

Unchanged responsibilities from the prior pass (action memory, ability
completion tokens, threat table storage) — no bugs found here beyond the
missing `[...]` on `Sort()`'s lambda, fixed below. Sort's predicate lambda
was also missing its capture list (harmless here since it captures nothing,
but still required syntax).

```cpp
// UAICognitiveComponent.h
// Copyright Phoenix Protocol. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "GameplayAbilitySpecHandle.h"
#include "UAICognitiveComponent.generated.h"

USTRUCT(BlueprintType)
struct FAshenActionHistoryEntry
{
 GENERATED_BODY()

 UPROPERTY(BlueprintReadOnly)
 FGameplayTag ActionTag;

 UPROPERTY(BlueprintReadOnly)
 float Timestamp = 0.0f;
};

USTRUCT(BlueprintType)
struct FAshenThreatEntry
{
 GENERATED_BODY()

 UPROPERTY(BlueprintReadOnly)
 TWeakObjectPtr<APawn> ThreatTarget;

 UPROPERTY(BlueprintReadOnly)
 float ThreatScore = 0.0f;
};

/**
 * @class UAICognitiveComponent
 * @brief Ledger component: action memory, ability-completion tokens, threat
 * table storage. Deliberately does NOT perform perception or scoring — that
 * responsibility lives in UAshenOath_ThreatPerceptionComponent, which writes
 * here via UpdateThreatTable(). Keeps this component a pure data ledger with
 * a stable, minimal write API.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAICognitiveComponent : public UActorComponent
{
 GENERATED_BODY()

public:
 UAICognitiveComponent();

 void RecordAction(const FGameplayTag& ActionTag);
 int32 GetRecentExecutionCount(const FGameplayTag& Tag, float WindowSeconds) const;

 void SetAbilityCompleted(const FGameplayAbilitySpecHandle& Handle);
 bool IsAbilityCompleted(const FGameplayAbilitySpecHandle& Handle) const;
 void ClearAbilityCompletion(const FGameplayAbilitySpecHandle& Handle);

 void UpdateThreatTable(const TArray<FAshenThreatEntry>& NewThreatEntries);
 APawn* GetPrimaryThreatTarget() const;

private:
 UPROPERTY(Transient)
 TArray<FAshenActionHistoryEntry> RecentActionJournal;

 const int32 MaxHistorySize = 8;

 UPROPERTY(Transient)
 TSet<FGameplayAbilitySpecHandle> CompletedAbilities;

 UPROPERTY(Transient)
 TArray<FAshenThreatEntry> ThreatTable;
};
```

```cpp
// UAICognitiveComponent.cpp
// Copyright Phoenix Protocol. All rights reserved.
#include "UAICognitiveComponent.h"
#include "Engine/World.h"

UAICognitiveComponent::UAICognitiveComponent()
{
 PrimaryComponentTick.bCanEverTick = false;
 RecentActionJournal.Reserve(MaxHistorySize);
}

void UAICognitiveComponent::RecordAction(const FGameplayTag& ActionTag)
{
 const float CurrentTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;

 // Shift-on-full is fine at MaxHistorySize == 8 (effectively free). If this
 // grows meaningfully, switch to a head-index circular buffer instead of
 // carrying an O(n) shift cost forward.
 if (RecentActionJournal.Num() >= MaxHistorySize)
 {
  RecentActionJournal.RemoveAt(0);
 }

 FAshenActionHistoryEntry NewEntry;
 NewEntry.ActionTag = ActionTag;
 NewEntry.Timestamp = CurrentTime;
 RecentActionJournal.Add(NewEntry);
}

int32 UAICognitiveComponent::GetRecentExecutionCount(const FGameplayTag& Tag, float WindowSeconds) const
{
 const float CurrentTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;
 int32 ExecutionCount = 0;

 for (const FAshenActionHistoryEntry& Entry : RecentActionJournal)
 {
  if (Entry.ActionTag == Tag && (CurrentTime - Entry.Timestamp) <= WindowSeconds)
  {
   ++ExecutionCount;
  }
 }
 return ExecutionCount;
}

void UAICognitiveComponent::SetAbilityCompleted(const FGameplayAbilitySpecHandle& Handle)
{
 CompletedAbilities.Add(Handle);
}

bool UAICognitiveComponent::IsAbilityCompleted(const FGameplayAbilitySpecHandle& Handle) const
{
 return CompletedAbilities.Contains(Handle);
}

void UAICognitiveComponent::ClearAbilityCompletion(const FGameplayAbilitySpecHandle& Handle)
{
 CompletedAbilities.Remove(Handle);
}

void UAICognitiveComponent::UpdateThreatTable(const TArray<FAshenThreatEntry>& NewThreatEntries)
{
 ThreatTable = NewThreatEntries;

 // Fixed: predicate lambda was missing its [] capture list (compile error,
 // even though it captures nothing — the brackets are still required).
 ThreatTable.Sort([](const FAshenThreatEntry& A, const FAshenThreatEntry& B)
 {
  return A.ThreatScore > B.ThreatScore;
 });
}

APawn* UAICognitiveComponent::GetPrimaryThreatTarget() const
{
 for (const FAshenThreatEntry& Entry : ThreatTable)
 {
  if (Entry.ThreatTarget.IsValid())
  {
   return Entry.ThreatTarget.Get();
  }
 }
 return nullptr;
}
```

---

## 5. `UAshenOath_ThreatPerceptionComponent` (new — the missing producer)

Sole owner of perception ingestion and threat-scoring policy. Writes into
`UAICognitiveComponent` through its existing `UpdateThreatTable` API — no
changes required to the ledger component. Zero-score (out-of-range)
candidates are dropped, not retained at score 0, so an empty threat table
genuinely means "no threat" and `EvaluateAction`'s idle-fallback path works
correctly instead of latching onto a stale out-of-range pawn.

```cpp
// AshenOath_ThreatPerceptionComponent.h
// Copyright Phoenix Protocol. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Perception/AIPerceptionTypes.h"
#include "AshenOath_ThreatPerceptionComponent.generated.h"

class UAIPerceptionComponent;
class UAICognitiveComponent;

USTRUCT(BlueprintType)
struct FAshenThreatScoringParams
{
 GENERATED_BODY()

 UPROPERTY(EditDefaultsOnly, Category = "Threat")
 float DistanceWeight = 1.0f;

 UPROPERTY(EditDefaultsOnly, Category = "Threat")
 float MaxEngagementRange = 6000.0f;

 UPROPERTY(EditDefaultsOnly, Category = "Threat")
 float DamageAggroWeight = 2.0f;

 UPROPERTY(EditDefaultsOnly, Category = "Threat")
 float DamageAggroHalfLifeSeconds = 4.0f;
};

/**
 * @class UAshenOath_ThreatPerceptionComponent
 * @brief Sole owner of perception ingestion and threat-scoring policy.
 * Reads UAIPerceptionComponent stimuli and externally-reported damage
 * events; writes results into UAICognitiveComponent via UpdateThreatTable().
 * No GAS includes — NotifyDamageReceived takes only primitive/engine types,
 * so the combat layer can call this without this component ever depending
 * on the ability system.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_ThreatPerceptionComponent : public UActorComponent
{
 GENERATED_BODY()

public:
 UAshenOath_ThreatPerceptionComponent();

 void NotifyDamageReceived(APawn* Instigator, float DamageAmount);

protected:
 virtual void BeginPlay() override;
 virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
 UFUNCTION()
 void HandlePerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

 void RecomputeThreatTable();
 float ScoreCandidate(const APawn* Candidate, float LastSeenAge) const;

 UPROPERTY(EditDefaultsOnly, Category = "Threat")
 FAshenThreatScoringParams ScoringParams;

 UPROPERTY(Transient)
 TWeakObjectPtr<UAIPerceptionComponent> PerceptionComp;

 UPROPERTY(Transient)
 TWeakObjectPtr<UAICognitiveComponent> CognitiveComp;

 // Instigator -> last damage timestamp. Decays independently of perception
 // staleness, so a target that breaks line-of-sight mid-fight still reads
 // as hostile for a short grace period.
 UPROPERTY(Transient)
 TMap<TWeakObjectPtr<APawn>, float> DamageAggroLog;
};
```

```cpp
// AshenOath_ThreatPerceptionComponent.cpp
// Copyright Phoenix Protocol. All rights reserved.
#include "AshenOath_ThreatPerceptionComponent.h"
#include "UAICognitiveComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "AIController.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"

UAshenOath_ThreatPerceptionComponent::UAshenOath_ThreatPerceptionComponent()
{
 PrimaryComponentTick.bCanEverTick = true;
 // Throttled — consistent with the significance-bucket philosophy: this
 // doesn't need to run every frame for every agent.
 PrimaryComponentTick.TickInterval = 0.25f;
}

void UAshenOath_ThreatPerceptionComponent::BeginPlay()
{
 Super::BeginPlay();

 const AAIController* AIController = Cast<AAIController>(GetOwner());
 if (!AIController)
 {
  UE_LOG(LogTemp, Warning, TEXT("%s must be owned by an AAIController"), *GetName());
  return;
 }

 PerceptionComp = AIController->FindComponentByClass<UAIPerceptionComponent>();
 if (UAIPerceptionComponent* Perception = PerceptionComp.Get())
 {
  Perception->OnTargetPerceptionUpdated.AddDynamic(
   this, &UAshenOath_ThreatPerceptionComponent::HandlePerceptionUpdated);
 }

 if (const APawn* Pawn = AIController->GetPawn())
 {
  CognitiveComp = Pawn->FindComponentByClass<UAICognitiveComponent>();
 }
}

void UAshenOath_ThreatPerceptionComponent::HandlePerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
 // Deliberately empty: perception state already lives inside
 // UAIPerceptionComponent's own table (GetKnownPerceivedActors). We don't
 // duplicate it into a shadow copy here — the throttled Tick below reads
 // directly from Perception on recompute instead.
}

void UAshenOath_ThreatPerceptionComponent::NotifyDamageReceived(APawn* Instigator, float DamageAmount)
{
 if (!Instigator || DamageAmount <= 0.0f)
 {
  return;
 }
 const float Now = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;
 DamageAggroLog.Add(TWeakObjectPtr<APawn>(Instigator), Now);
}

void UAshenOath_ThreatPerceptionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
 Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
 RecomputeThreatTable();
}

float UAshenOath_ThreatPerceptionComponent::ScoreCandidate(const APawn* Candidate, float LastSeenAge) const
{
 if (!Candidate)
 {
  return 0.0f;
 }

 const AActor* SelfOwner = GetOwner();
 const AAIController* SelfController = SelfOwner ? Cast<AAIController>(SelfOwner) : nullptr;
 const APawn* SelfPawn = SelfController ? SelfController->GetPawn() : nullptr;
 if (!SelfPawn)
 {
  return 0.0f;
 }

 const float Distance = FVector::Dist(SelfPawn->GetActorLocation(), Candidate->GetActorLocation());
 if (Distance > ScoringParams.MaxEngagementRange)
 {
  return 0.0f;
 }

 const float DistanceScore = ScoringParams.DistanceWeight * (1.0f - (Distance / ScoringParams.MaxEngagementRange));
 const float RecencyScore = FMath::Exp(-LastSeenAge);

 float DamageScore = 0.0f;
 if (const float* LastHitTime = DamageAggroLog.Find(TWeakObjectPtr<APawn>(const_cast<APawn*>(Candidate))))
 {
  const float Now = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;
  const float Age = Now - *LastHitTime;
  DamageScore = ScoringParams.DamageAggroWeight *
   FMath::Pow(0.5f, Age / ScoringParams.DamageAggroHalfLifeSeconds);
 }

 return DistanceScore + RecencyScore + DamageScore;
}

void UAshenOath_ThreatPerceptionComponent::RecomputeThreatTable()
{
 UAIPerceptionComponent* Perception = PerceptionComp.Get();
 UAICognitiveComponent* Cognitive = CognitiveComp.Get();
 if (!Perception || !Cognitive)
 {
  return;
 }

 TArray<AActor*> PerceivedActors;
 Perception->GetKnownPerceivedActors(nullptr, PerceivedActors);

 TArray<FAshenThreatEntry> NewEntries;
 NewEntries.Reserve(PerceivedActors.Num());

 for (AActor* Actor : PerceivedActors)
 {
  APawn* CandidatePawn = Cast<APawn>(Actor);
  if (!CandidatePawn)
  {
   continue;
  }

  FActorPerceptionBlueprintInfo Info;
  Perception->GetActorsPerception(Actor, Info);

  float BestAge = TNumericLimits<float>::Max();
  for (const FAIStimulus& Stimulus : Info.LastSensedStimuli)
  {
   if (Stimulus.WasSuccessfullySensed())
   {
    BestAge = FMath::Min(BestAge, Stimulus.GetAge());
   }
  }
  if (BestAge == TNumericLimits<float>::Max())
  {
   continue; // no currently-valid sense for this actor
  }

  FAshenThreatEntry Entry;
  Entry.ThreatTarget = CandidatePawn;
  Entry.ThreatScore = ScoreCandidate(CandidatePawn, BestAge);

  // Fixed: zero-score (out-of-range) candidates are dropped, not kept
  // in the table at score 0. Keeping them meant GetPrimaryThreatTarget
  // could return a stale, out-of-range pawn once nothing else
  // outranked it, so EvaluateAction's idle-fallback branch (triggered
  // by a null target) never fired — the table was never truly empty.
  if (Entry.ThreatScore > 0.0f)
  {
   NewEntries.Add(Entry);
  }
 }

 Cognitive->UpdateThreatTable(NewEntries);
}
```

---

## 6. Performance-Driven Cognitive Scalability

DOD guidelines (unchanged from prior pass, now actually honored by the
cached-component fixes above rather than contradicted by them):

1. Flat structs over polymorphic hot-path state.
2. `alignas(16)` on vectorization-critical structs.
3. Active cache pinning of distance/vector data centrally — the threat
   perception component above is throttled at 0.25s intervals specifically
   to respect this.

### Significance Buckets

| Bucket | Range (uu) | Evaluation Frequency | Animation State | EQS Rate |
|---|---|---|---|---|
| 0: High | 0–1200 | Every frame | Full bone eval | 10 Hz |
| 1: Medium | 1200–3500 | 10 Hz | Skip alternating frames | 2 Hz |
| 2: Low | 3500–6000 | 2 Hz | Rigidbody eval | 0.5 Hz |
| 3: Culled | 6000+ | Suspended | Freeze pose | Terminated |

---

## 7. Replicated Event Sourcing (LAW-003)

$$State(t)=State(0)+\sum_{i=1}^{n}Event_{i}$$

Discrete timestamped events (`Event.Posture.Broken`, `Event.Stance.Enraged`)
replicated instead of continuous attribute streams; clients reconstruct
presentation deterministically from the event log.

---

## 8. Implementation Roadmap

```
+---------------------------------------------------------------------------------+
|                       PHASE I: COGNITIVE SCAFFOLDING                            |
|  - Integrate StateTree + GAS schemas into AAshenCombatCharacter                 |
|  - Integrate UAICognitiveComponent with flat ring buffers and completion maps   |
+---------------------------------------------------------------------------------+
                                         |
                                         v
+---------------------------------------------------------------------------------+
|                        PHASE II: REACTIVE SENSORY LAYER                         |
|  - Deploy UAshenOath_ThreatPerceptionComponent per agent                        |
|  - Wire NotifyDamageReceived into the combat/GAS damage-application path        |
+---------------------------------------------------------------------------------+
                                         |
                                         v
+---------------------------------------------------------------------------------+
|                        PHASE III: SCALABILITY TUNING                            |
|  - Register AI controllers with the central USignificanceManager               |
|  - Confirm ThreatPerception's 0.25s tick interval scales at target agent counts |
+---------------------------------------------------------------------------------+
                                         |
                                         v
+---------------------------------------------------------------------------------+
|                       PHASE IV: ENTROPY AND ANTI-ENTROPY                        |
|  - Deploy LAW-041 Markovian utility evaluations inside EvaluateAction tasks     |
|  - Add auditor check: ActionTypeTag/AbilityTag parity across co-resident states |
|  - Implement LAW-003 transaction journals for zero-desync client simulations    |
+---------------------------------------------------------------------------------+
```

## Open Items Not Resolved In-File

- **Tag-parity enforcement** between `EvaluateAction.ActionTypeTag` and
  `ExecuteAbility.AbilityTag` requires StateTree-asset-level introspection
  (walking sibling/child states in the editor), not something a single task
  struct can self-check at compile time. Recommend as a dedicated
  AOP-MECS-TOOLKIT auditor rule rather than solving here.
